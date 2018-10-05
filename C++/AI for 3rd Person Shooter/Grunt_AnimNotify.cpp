// Fill out your copyright notice in the Description page of Project Settings.

/*Copyright Nicholas Ruppel 2016
Author: Nicholas Ruppel
*/
#include "GD42_Torment.h"
#include "Grunt_AnimNotify.h"
#include "Torment_AIController.h"
#include "FactoryActor.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Engine.h"


void UGrunt_AnimNotify::Notify(USkeletalMeshComponent* skelMeshComp, UAnimSequenceBase* animation)
{
	//if no skeletalmesh retur n null
	if (!skelMeshComp)
		return;

	APawn* selfpawn = Cast<APawn>(skelMeshComp->GetOwner());//cast self pawn to owner

	if (selfpawn)
	{
		//grab the ai controller
		ATorment_AIController* aiController = Cast<ATorment_AIController>(selfpawn->GetController());//cast to the ai controller

		if (aiController)
		{
			//grab blackboard itself
			UBlackboardComponent* blackBoardComp = aiController->GetBlackboard();

			if (blackBoardComp) {
				// cast the pawn and get the blackboaed key
				APawn * enemypawn = Cast<APawn>(blackBoardComp->GetValueAsObject("Enemy"));

				

				//Shoot Projectile block
				const FVector myLoc = selfpawn->GetActorLocation(); // my location is self pawn
				FVector direction = enemypawn->GetActorLocation() - myLoc;
				direction.Normalize();
				AFactoryActor::CreateProjectile(myLoc + direction*100.0f , direction.Rotation());
			}
		}
	}
}

