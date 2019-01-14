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
	
		ATank* GetConrolledTank() const;

	void BeginPlay() override;
	
	
};
