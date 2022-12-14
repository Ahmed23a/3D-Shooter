// Fill out your copyright notice in the Description page of Project Settings.


#include "KillThemAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"




void AKillThemAllGameMode::PawnKilled(APawn* PawnKilled)
{
    Super::PawnKilled(PawnKilled);

    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    if (PlayerController != nullptr)
    {
               
        PlayerController->GameHasEnded(nullptr, false);
        EndGame(false);
    }


    for (AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld()))
    {
        if (!Controller->IsDead())
        {
            return;
        }
    }

    EndGame(true);
    
    //For loop over ShooterAI in world:
        // is not dead 
            // return
    
    //End game
}

void AKillThemAllGameMode::EndGame(bool bIsPlayerWinner)
{
    for (AController* Controller : TActorRange<AController>(GetWorld()))
    {
       // bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
       // Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }

}
