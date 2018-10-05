// Fill out your copyright notice in the Description page of Project Settings.

/*Copyright Nicholas Ruppel 2016
Author: Nicholas Ruppel
*/
#pragma once

#include "AIController.h"
#include "Torment_AIController.generated.h"

/**
 * 
 */
UCLASS()
class GD42_TORMENT_API ATorment_AIController : public AAIController
{
	GENERATED_BODY()
		//create class for pawnsensing
	class UPawnSensingComponent* pawnSensingComp;

	//make OnSeePlayer UFuntion
	UFUNCTION()
		void OnSeePlayer(APawn* tPawn);

	//pointers for blackboard and behavior tree components
	UBehaviorTreeComponent* behaviorTreeComp;
	UBlackboardComponent* blackBoardComp;

	virtual void BeginPlay()override;

	virtual void Tick(float deltaSeconds)override;

	virtual void Possess(APawn* inPawn)override;

public:

	ATorment_AIController();
	//get blackboard and return blackboardcomp pointer
	UBlackboardComponent* GetBlackboard() {
		return blackBoardComp;
	}

	void RagDoll(APawn* selfPawn);
};