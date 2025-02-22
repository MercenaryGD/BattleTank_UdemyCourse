// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;
/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RithtTrackToSet);

		UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendMoveForward(float Throw);

		UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendMoveRight(float Throw);

		UFUNCTION(BlueprintCallable, Category = "Input")
			void IntendMoveLeft(float Throw);

		UFUNCTION(BlueprintCallable, Category = "Input")
			void IntendMoveBack(float Throw);

		virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	
private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RithtTrack = nullptr;
};
