// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterChar.h"


void AShooterAIController::BeginPlay() 
{
    Super::BeginPlay();
    
    //Checking if we have AIBehavior Tree so we can acess and run  it here 
    if (AIBehavior != nullptr)
    {
        RunBehaviorTree(AIBehavior);
        APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

        GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());

    }

}

void AShooterAIController::Tick(float DeltaSeconds) 
{
    Super::Tick(DeltaSeconds);
    
    // APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    // MoveToActor(PlayerPawn, 200);

    // if (LineOfSightTo(PlayerPawn))
    // {
    //     //Setting PlayerLocation and LastKnownPlayerLocation
    //     GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
    //     GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());

    // }
    // else
    // {
    //     // clear PlayerLocation
    //     GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
    // }


    //lineOfSight => if the AI can see the player without any obstacles in between
    //  AI moves to the char and setFocus
    //else
    //clearFocus and stop movement    
        
}

bool AShooterAIController::IsDead() const
{
    AShooterChar* ControlledCharacter = Cast<AShooterChar>(GetPawn());
    if (ControlledCharacter != nullptr)
    {
        
        return ControlledCharacter->IsDead();
    }
    
    return true;

}

