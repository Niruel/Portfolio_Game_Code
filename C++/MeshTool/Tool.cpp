// Fill out your copyright notice in the Description page of Project Settings.

#include "GD42_Torment.h"
#include "Tool.h"
#include "Engine.h"

ATool::ATool()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("MeshToolRoot"));

	meshBase = CreateDefaultSubobject<USceneComponent>(TEXT("MeshBase"));
	meshBase->AttachTo(RootComponent);


	meshFirstStart = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshFirstStart"));
	meshFirstStart->AttachTo(meshBase);


	startDraggingPoint = GetActorLocation();


}


void ATool::PostInitProperties()
{
	Super::PostInitProperties();

}

#if WITH_EDITOR
void ATool::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	BaseMeshSet();
	Super::PostEditChangeProperty(PropertyChangedEvent);

}
#endif

// Called when the game starts or when spawned
void ATool::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}
//set the base mesh function
void ATool::BaseMeshSet()
{
	// checks if mesh start is vaild
	if (meshStart) {
		hasMeshStart = true;



	}
	else
		hasMeshStart = false;


	// checks if mesh end is vaild
	if (meshEnd) {

		hasMeshEnd = true;
	}
	else
		hasMeshEnd = false;


	if (hasMeshStart == true)
	{
		meshFirstStart->SetStaticMesh(meshStart);

	}
	else {
		meshFirstStart->SetStaticMesh(middleMesh);
	}


	if (endMeshPoint != FVector::ZeroVector)
	{

		if (meshArray.Num() > 0) {

			//remove all elements of meshArray
			for (int i = 0; i < meshArray.Num(); i++) {

				//	RemoveFromRoot();
				meshArray[i]->DestroyComponent();
			}
		}

		numberOfInstances = (int)(endMeshPoint.Size() / meshLength);//floors the vector

		FVector endPointUnit = endMeshPoint - startDraggingPoint;
		endPointUnit.Normalize();
	
		extent = middleMesh->GetBounds().GetBox().GetSize();
		UE_LOG(LogTemp, Warning, TEXT("SetMesh Extent.X : %f, %f, %f, %f"), extent.X, extent.Y, extent.Z, radius);

		if (axisEnum == EAxisDirectionEnum::AD_X) {

			meshLength = extent.X;
		}
		if (axisEnum == EAxisDirectionEnum::AD_Y) {

			meshLength = extent.Y;
		}

		// spawn body if != 0 or != max
		for (int i = 0; i < numberOfInstances; i++)
		{
			currentIndex = i;

			if (currentIndex == 0)
			{
				SetMesh(i, endPointUnit);

			}
			else {

				if (currentIndex < numberOfInstances - 1)
				{
					SetMesh(i, endPointUnit);
				}
				else {

					if (!hasMeshEnd)
					{
						SetMesh(i, endPointUnit);
					}
					else
					{
						LastMeshPlaced(i, endPointUnit);

					}
				}
			}
		}


	}

}


void ATool::SetMesh(int index, FVector direction)
{

	UStaticMeshComponent *meshInstance;
	FString meshname = FString::Printf(TEXT("meshInstance%04d"), index);


	meshXPlacement = (currentIndex + 1)*meshLength;

	meshInstance = NewObject<UStaticMeshComponent>(this);

	if (middleMesh)
	{
		meshInstance->SetStaticMesh(middleMesh);
		meshInstance->AttachTo(meshBase);
		meshInstance->SetRelativeLocation(startDraggingPoint + direction * meshXPlacement);
		meshInstance->SetRelativeRotation(meshBodyRotation);

	}


	meshArray.Add(meshInstance);
}
void ATool::LastMeshPlaced(int index, FVector direction)
{

	UStaticMeshComponent *meshInstance;
	FString meshname = FString::Printf(TEXT("meshInstance%04d"), index);


	meshXPlacement = (currentIndex + 1)*meshLength;

	meshInstance = NewObject<UStaticMeshComponent>(this);


	if (meshEnd)
	{
		meshInstance->SetStaticMesh(meshEnd);
		meshInstance->AttachTo(meshBase);
		meshInstance->SetRelativeLocation(startDraggingPoint + direction * meshXPlacement);
		meshInstance->SetRelativeRotation(meshBodyRotation);
	}

	meshArray.Add(meshInstance);
}