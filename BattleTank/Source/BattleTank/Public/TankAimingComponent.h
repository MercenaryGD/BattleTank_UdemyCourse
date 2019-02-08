
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
		void Initialise(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation, float LaunchSpeed);

private:
	

	void MoveBarrelTowrads(FVector AimDirection);



	void MoveTurret(FVector AimDirection);
protected:
	UPROPERTY(BlueprintReadOnly,Category="State")
	EFiringState FiringState = EFiringState::Reloading;
};