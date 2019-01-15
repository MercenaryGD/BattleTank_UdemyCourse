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

void ATankPlayerController_WORK::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

}
void ATankPlayerController_WORK::AimTowardsCrosshair()
{
	if (!GetConrolledTank()) { return; }
	FVector HitLocation;
	if(GetSightRayHitLocation(HitLocation))
	{
		
		
		UE_LOG (LogTemp,Warning,TEXT("HitLocation : %s"),*HitLocation.ToString())
	
	
	}
}
bool ATankPlayerController_WORK::GetSightRayHitLocation(FVector& HitOutLocation) const {
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY *CrossHairYLocation);
	UE_LOG(LogTemp,Warning,TEXT("Screen Location : %s"),*ScreenLocation.ToString())
	return true;
}

