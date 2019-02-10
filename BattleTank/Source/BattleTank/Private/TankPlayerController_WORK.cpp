// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController_WORK.h"
#include "TankAimingComponent.h"
#include "Tank.h"
#include "BattleTank.h"



void ATankPlayerController_WORK::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
	if(ensure(AimingComponent))
	{FoundAimingComponent(AimingComponent);}
	else
	{UE_LOG(LogTemp,Warning,TEXT("Aiming component is fucked")) }
}

void ATankPlayerController_WORK::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController_WORK::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController_WORK::AimTowardsCrosshair()
{
	if (!ensure(GetControlledTank())) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation)) // Has "side-effect", is going to line trace
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController_WORK::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	// "De-project" the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// Line-trace along that LookDirection, and see what we hit (up to max range)
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}

	return true;
}

bool ATankPlayerController_WORK::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false; // Line trace didn't succeed
}

bool ATankPlayerController_WORK::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // To be discarded
	return  DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}