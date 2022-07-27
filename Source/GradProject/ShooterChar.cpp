// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterChar.h"
#include "Gun.h"
#include "Components/CapsuleComponent.h"
#include "GradProjectGameModeBase.h"


// Sets default values
AShooterChar::AShooterChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterChar::BeginPlay()
{
	Super::BeginPlay();
	
	Health = MaxHealth; 

	Gun = GetWorld()->SpawnActor<AGun>(GunClass);

	//To hide the actuall gun 
	//to get hold of mesh component from subClass 
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform,TEXT("WeaponSocket"));
	Gun->SetOwner(this);
}

bool AShooterChar::IsDead() const
{
	//Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform,TEXT("WeaponSocket"));
	//Gun->SetOwner(this);
	
	return Health <= 0;
}

float AShooterChar::GetHealthPercent() const
{
	return Health / MaxHealth;
}

// Called every frame
void AShooterChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// moving forward and backward
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AShooterChar::MoveForward);

	// Pitch => up and down
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);

	// moving right and left 
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AShooterChar::MoveRight);

	// Yaw => right and left 
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	// jump
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);

	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &AShooterChar::Shoot);

}

float AShooterChar::TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator,
 AActor *DamageCauser) 
{
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;
	UE_LOG(LogTemp, Warning, TEXT("Health left %f"), Health);
	
	if(IsDead())
	{
		AGradProjectGameModeBase* GameMode = GetWorld()->GetAuthGameMode<AGradProjectGameModeBase>();
		if (GameMode != nullptr)
		{
			GameMode->PawnKilled(this);
		}

		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);			
	}

	return DamageToApply;
}

void AShooterChar::MoveForward(float AxisValue) 
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AShooterChar::MoveRight(float AxisValue) 
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AShooterChar::increaseKills()
{
	Kills += 1;
}

void AShooterChar::Shoot()
{
	Gun->PullTrigger();

}




//void AShooterChar::LookUp(float AxisValue)
//{
//	AddControllerPitchInput(AxisValue);
//}

