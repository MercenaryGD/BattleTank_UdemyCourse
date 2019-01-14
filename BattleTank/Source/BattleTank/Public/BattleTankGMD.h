// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "BattleTankGMD.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ABattleTankGMD : public APlayerController
{
	GENERATED_BODY()


		ATank* GetConrolledTank() const;

	
};
