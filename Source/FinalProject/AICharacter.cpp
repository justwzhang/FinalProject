// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter.h"
#include "AICharacterController.h"
#include "Perception/PawnSensingComponent.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values
AAICharacter::AAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CollisionCapsule->InitCapsuleSize(55.0f, 150.0f);
	CollisionCapsule->SetupAttachment(RootComponent);

	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->SetPeripheralVisionAngle(300.0f);

	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	TriggerCapsule->InitCapsuleSize(55.f, 96.0f);
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
}

// Called when the game starts or when spawned
void AAICharacter::BeginPlay()
{
	Super::BeginPlay();
	AAICharacterController* AIController = Cast<AAICharacterController>(GetController());
	AIController->SetPlayerCaught(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	/*if (PawnSensingComp) {
		PawnSensingComp->OnSeePawn.AddDynamic(this, &AAICharacter::OnPlayerCaught);
	}*/
}

// Called every frame
void AAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAICharacter::OnPlayerCaught(APawn* pawn) {
	//AAICharacterController* AIController = Cast<AAICharacterController>(GetController());
	//if (AIController) {
	//	/*GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("SeePlayer"));*/
	//	AIController->SetPlayerCaught(pawn);
	//}
}
