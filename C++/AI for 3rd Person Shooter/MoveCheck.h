// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "MoveCheck.generated.h"

/**
 * 
 */
UCLASS()
class GD42_TORMENT_API UMoveCheck : public UBTTaskNode
{
	GENERATED_BODY()
	 
		//create execute task
		virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory)override;

		virtual FString GetStaticDescription() const override;
	
		void MoveToLoc(APawn* selfpawn, APawn* enemyPawn,float desierdDist, UBehaviorTreeComponent& ownerComp);
	
};
