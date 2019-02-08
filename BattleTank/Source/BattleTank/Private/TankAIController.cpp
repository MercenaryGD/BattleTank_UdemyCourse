
#include "TankAIController.h"
#include "Tank.h"
#include "BattleTank.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
		// TODO Move towards the player
		auto PlayerPawn = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
		auto ControlledTank = Cast<ATank>(GetPawn());
		// Aim towards the player
		if(PlayerPawn){
		
			MoveToActor(PlayerPawn, AcceptanceRadius);

		ControlledTank->AimAt(PlayerPawn->GetActorLocation());
		
		// Fire if ready
		ControlledTank->Fire();
	}
}

