// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacterController.h"
#include "AICharacter.h"
#include "PatrolPoint.h"
#include <Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeComponent.h>
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include <Runtime/AIModule/Classes/BehaviorTree/BehaviorTree.h>
#include <Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h>

AAICharacterController::AAICharacterController()
{
	BehaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
	LocationToGoKey = "LocationToGo";
	PlayerKey = "Target";
	CurrentPoint = 0;
}

void AAICharacterController::OnPossess(APawn* ThePawn)
{
	Super::OnPossess(ThePawn);

	AAICharacter* theCharacter = Cast<AAICharacter>(ThePawn);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Possessing Pawn"));
	if (theCharacter) {
		AICharacter = theCharacter;
		if (theCharacter->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*(theCharacter->BehaviorTree->BlackboardAsset));
		}
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), APatrolPoint::StaticClass(), TargetPoints);
		BehaviorTreeComp->StartTree(*theCharacter->BehaviorTree);
	}
}

void AAICharacterController::SetPlayerCaught(APawn* pawn) {
	if (BlackboardComp) {
		BlackboardComp->SetValueAsObject(PlayerKey, pawn);
	}
}
