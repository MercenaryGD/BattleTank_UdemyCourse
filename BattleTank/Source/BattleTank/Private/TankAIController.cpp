// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetPlayerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank is not find player"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT(" AI Tank is  find player : %s"), *(ControlledTank->GetName()))
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		GetConrolledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAIController::GetConrolledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank()
{
	auto Pawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!Pawn) {
		return nullptr;
	}
	else
	{
		return Cast<ATank>(Pawn);
	}
}

