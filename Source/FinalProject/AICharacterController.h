// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include <Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeComponent.h>
#include "AICharacterController.generated.h"

/**
 * 
 */
UCLASS()
class FINALPROJECT_API AAICharacterController : public AAIController
{
	GENERATED_BODY()
	UBehaviorTreeComponent* BehaviorTreeComp;
	UBlackboardComponent* BlackboardComp;

	UPROPERTY(EditDefaultsOnly, Category = AI)
		FName LocationToGoKey;

	UPROPERTY(EditDefaultsOnly, Category = AI)
		FName PlayerKey;

	TArray<AActor*> TargetPoints;

	virtual void OnPossess(APawn* ThePawn) override;
	ACharacter* AICharacter;

public:
	AAICharacterController();
	FORCEINLINE UBlackboardComponent* GetBackboardComponent() const { return BlackboardComp; }
	FORCEINLINE TArray<AActor*> GetTargetPoints() const { return TargetPoints; }
	int32 CurrentPoint;

	void SetPlayerCaught(APawn* pawn);

	//// Called every frame
	//virtual void Tick(float DeltaTime) override;


};
