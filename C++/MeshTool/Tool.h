// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Tool.generated.h"



UENUM(BlueprintType)
enum class EAxisDirectionEnum : uint8
{
	AD_X  UMETA(DisplayName = "X axis"),
	AD_Y  UMETA(DisplayName = "Y axis")
};

UCLASS()
class GD42_TORMENT_API ATool : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATool();

	virtual void PostInitProperties() override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Enum)
		EAxisDirectionEnum  axisEnum;

	UPROPERTY(EditAnywhere)
		UStaticMesh *meshStart;

	UPROPERTY(EditAnywhere)
		UStaticMesh *middleMesh;

	UPROPERTY(EditAnywhere)
		UStaticMesh *meshEnd;

	UPROPERTY()
		UStaticMeshComponent *meshFirstStart;

	UPROPERTY()
		USceneComponent *meshBase;

	UPROPERTY()
		USceneComponent *meshTool;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory", Meta = (MakeEditWidget = true))
		FVector endMeshPoint;





	UPROPERTY(EditAnywhere)
		TArray<UStaticMeshComponent*> meshArray;// static mesh array


	FVector startDraggingPoint;

	FVector origin;
	FVector extent;
	float radius;




private:
	bool hasMeshStart;
	bool hasMeshEnd;

	float meshLength = 100.0f;
	float meshBodyLength;
	float meshStartLength;
	float meshEndLength;
	float meshXPlacement;

	int numberOfInstances;
	int currentIndex;

	FRotator meshBodyRotation;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	//set the base mesh
	void BaseMeshSet();

	//Set mesh plus middle mesh 
	void SetMesh(int index, FVector direction);

	//places last end mesh
	void LastMeshPlaced(int index, FVector direction);
};