// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController_WORK.h"

void ATankPlayerController_WORK::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetConrolledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp,Warning,TEXT("Tank is not proccesing"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank is  proccesing: %s"), *(ControlledTank->GetName()))
	}
}

ATank * ATankPlayerController_WORK::GetConrolledTank() const
{
	return Cast<ATank>(GetPawn());
}

