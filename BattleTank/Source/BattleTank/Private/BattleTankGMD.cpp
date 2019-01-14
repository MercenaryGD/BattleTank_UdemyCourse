// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankGMD.h"
#include "GameFramework/Controller.h"


ATank * ABattleTankGMD::GetConrolledTank() const
{
	return Cast<ATank>(GetPawn());
}
