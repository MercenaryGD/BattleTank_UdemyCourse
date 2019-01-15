// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "ObjectMacros.h"
#include "TankPlayerController_WORK.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController_WORK : public APlayerController
{
	GENERATED_BODY()
public:
		ATank* GetConrolledTank() const;
		
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
private:
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector & HitOutLocation) const;
	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.3333;
};
