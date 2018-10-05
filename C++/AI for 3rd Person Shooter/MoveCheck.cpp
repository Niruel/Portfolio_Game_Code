// Fill out your copyright notice in the Description page of Project Settings.

#include "GD42_Torment.h"
#include "MoveCheck.h"
#include "Torment_AIController.h"
#include "FactoryActor.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"



EBTNodeResult::Type UMoveCheck::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory)
{
	//get refrence to the black board component 
	UBlackboardComponent* blackBoardComp = ownerComp.GetBlackboardComponent();

	if (blackBoardComp)
	{
		APawn* selfpawn = Cast<APawn>(blackBoardComp->GetValueAsObject("Enemy"));


		ATorment_AIController* gruntControl= Cast<ATorment_AIController>(ownerComp.GetOwner());

		if (gruntControl == NULL)
		{
			return EBTNodeResult::Failed;
		}
		else
		{
			FVector destination = blackBoardComp->GetValueAsVector("DesierdLocation");
			gruntControl->MoveToLocation(destination, 15.0f);
			return EBTNodeResult::Succeeded;
		}
		
	}
	return EBTNodeResult::Failed;
}
void UMoveCheck::MoveToLoc(APawn* selfpawn, APawn* enemyPawn,float desierdDist, UBehaviorTreeComponent& ownerComp)
{
	FVector gruntLoc = selfpawn->GetActorLocation();
	FVector playerLoc = enemyPawn->GetActorLocation();
	FVector currentDist = playerLoc - gruntLoc;
	float dist= currentDist.Size();
	float moveDist = dist - desierdDist;
	FVector moveVect = currentDist*moveDist;
	FVector newPost = gruntLoc + moveVect;

	UBlackboardComponent* bbComp = ownerComp.GetBlackboardComponent();
	//FVector newPos = bbComp->SetValueAsVector("DesierdLocation", newPos);
}

FString UMoveCheck::GetStaticDescription()const
{
	return "Move to Desierd location to shoot";
}
