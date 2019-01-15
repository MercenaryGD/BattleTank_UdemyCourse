// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController_WORK.h"
#include "WorldCollision.h"
#include "Vector.h"



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
		GetConrolledTank()->AimAt(HitLocation);
	}
}
bool ATankPlayerController_WORK::GetSightRayHitLocation(FVector& HitOutLocation) const {
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY *CrossHairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Screen Location : %s"), *ScreenLocation.ToString()))
		GetLookVectorHitLocation(LookDirection, HitOutLocation);

	}
		return true;
}
bool ATankPlayerController_WORK::GetLookVectorHitLocation(FVector& LookDirection, FVector& HitLocation)const 
{
	FHitResult HITRESULT;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + LookDirection * LineTraceRange;
	if (GetWorld()->LineTraceSingleByChannel(HITRESULT,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility))
	{
		HitLocation=HITRESULT.Location;
			return true;
	}
	return false;
}
bool ATankPlayerController_WORK::GetLookDirection(FVector2D& ScreenLocation,FVector& LookDirection) const
{

	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
	
}
