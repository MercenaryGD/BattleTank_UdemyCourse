
#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;

UENUM()
enum class EFiringState:uint8
{
	Reloading,
	Aiming,
	Locked

};



UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	
	void MoveBarrelTowards(FVector AimDirection);
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
protected:
	UPROPERTY(BlueprintReadOnly,Category="State")
	EFiringState FiringState = EFiringState::Reloading;
};