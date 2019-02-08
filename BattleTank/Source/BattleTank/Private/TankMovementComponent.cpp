// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RithtTrackToSet)
{
	if (!LeftTrackToSet || !RithtTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RithtTrack = RithtTrackToSet;
	UE_LOG(LogTemp,Warning,TEXT("lol kek"))
}



void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveForward(ForwardThrow);
	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendMoveRight(RightThrow);
}
void UTankMovementComponent::IntendMoveForward(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RithtTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendMoveRight(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RithtTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::IntendMoveLeft(float Throw)
{
	LeftTrack->SetThrottle(-Throw);
	RithtTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendMoveBack(float Throw)
{
	LeftTrack->SetThrottle(-Throw);
	RithtTrack->SetThrottle(-Throw);
}
