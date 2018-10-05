// Fill out your copyright notice in the Description page of Project Settings.

/*Copyright Nicholas Ruppel 2016
Author: Nicholas Ruppel
*/

#include "GD42_Torment.h"
#include "Torment_AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/PawnSensingComponent.h"
#include "FactoryActor.h"
#include "Engine.h"

ATorment_AIController::ATorment_AIController()
{
	//Creation for behavior tree and blackboard
	behaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("behaviorTreeComp"));
	blackBoardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("blackBoardComp"));

	//create pawnSensingComponent
	pawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("pawnSensingComp"));
	pawnSensingComp->SetPeripheralVisionAngle(90.0f);
	pawnSensingComp->SightRadius = (2000);
	pawnSensingComp->SetSensingUpdatesEnabled(true);
	pawnSensingComp->SetSensingInterval(0.5f);
}

void ATorment_AIController::BeginPlay()
{
	Super::BeginPlay();
	//start pawn sensing
	if (pawnSensingComp)
	{
		pawnSensingComp->OnSeePawn.AddDynamic(this, &ATorment_AIController::OnSeePlayer);
	}

}
//called every frame
void ATorment_AIController::Tick(float deltaSeconds)
{

	Super::Tick(deltaSeconds);
	//check if z velocity is positive
	APawn* selfpawn=GetPawn();
	//RagDoll(selfpawn);
}
// possess 
void ATorment_AIController::Possess(APawn* inPawn)
{
	Super::Possess(inPawn);

	//load behavior tree and blackboard
	UBehaviorTree *behaviorTreeObject = AFactoryActor::LoadObjFromPath<UBehaviorTree>("BehaviorTree'/Game/Torment/Blueprints/BT_Grunt.BT_Grunt'");
	UBlackboardData *blackBoardData = AFactoryActor::LoadObjFromPath<UBlackboardData>("BlackboardData'/Game/Torment/Blueprints/BB_Grunt.BB_Grunt'");
	
	//initalize blackboard keys and start behavior tree
	blackBoardComp->InitializeBlackboard(*blackBoardData);
	behaviorTreeComp->StartTree(*behaviorTreeObject);
}
// on see player connects to pawnsensing component
void ATorment_AIController::OnSeePlayer(APawn* pawn)
{
	FVector fooBar = pawn->GetActorForwardVector();
	
	// call both player controllers
	APlayerController* charController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	APlayerController* charController2 = UGameplayStatics::GetPlayerController(GetWorld(), 1);
	//charController -> AFactoryActor::LoadObjFromPath<APlayerController>("Blueprint'/Game/Torment/Blueprints/BP_PlayerCharacter.BP_PlayerCharacter'");
	
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, "Enemy found");
	// if one or the other is found init blackboard keys
	if ( (pawn == charController->GetCharacter()) || ( pawn == charController2->GetCharacter()) ){
	
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, pawn->GetName());

		blackBoardComp->SetValueAsObject("Enemy", pawn);
		blackBoardComp->SetValueAsFloat("DistanceToTarget", 1000.0f);
		blackBoardComp->SetValueAsVector("DesierdLocation",fooBar);
	}
	
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, "Enemy found");
//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, "Enemy found");
	
	

}

void ATorment_AIController::RagDoll(APawn* selfPawn)
{
	float verticalVelocity = selfPawn->GetVelocity().Z;
	USkeletalMeshComponent *mesh = selfPawn->FindComponentByClass<USkeletalMeshComponent>();

	if (verticalVelocity > 0)
	{
		//call grunt skeletal mesh
		
		mesh->SetSimulatePhysics(true);
		mesh->WakeAllRigidBodies();
				
	}
	else
	{
		mesh->PutAllRigidBodiesToSleep();
		mesh->SetAllBodiesPhysicsBlendWeight(0);
		mesh->SetSimulatePhysics(false);

		return;
	}
}