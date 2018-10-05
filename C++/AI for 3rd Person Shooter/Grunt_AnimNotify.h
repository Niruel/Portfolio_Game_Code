// Fill out your copyright notice in the Description page of Project Settings.

/*Copyright Nicholas Ruppel 2016
Author: Nicholas Ruppel
*/
#pragma once

#include "Animation/AnimNotifies/AnimNotify.h"
#include "Grunt_AnimNotify.generated.h"

/**
 * 
 */
UCLASS()
class GD42_TORMENT_API UGrunt_AnimNotify : public UAnimNotify
{
	GENERATED_BODY()
	
	
public:
	//crate notify 
	virtual void Notify(USkeletalMeshComponent* skelMeshComp, UAnimSequenceBase* animation)override;
	
	
};
