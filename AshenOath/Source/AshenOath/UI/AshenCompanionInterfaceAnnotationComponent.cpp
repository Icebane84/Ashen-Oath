// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenCompanionInterfaceAnnotationComponent.h"

UAshenCompanionInterfaceAnnotationComponent::UAshenCompanionInterfaceAnnotationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionInterfaceAnnotationComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenCompanionInterfaceAnnotationComponent::ApplyCompanionAnnotations(FName MemoryNodeID)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionInterfaceAnnotationComponent: Applied companion sketches & runes for memory node %s"), *MemoryNodeID.ToString());
}

void UAshenCompanionInterfaceAnnotationComponent::AddJournalAnnotation(FName CompanionID, FName AnnotationID, const FString& TextContent)
{
	TotalAnnotationsCount++;
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionInterfaceAnnotationComponent: Added journal annotation %s by %s (Total: %d)."), *AnnotationID.ToString(), *CompanionID.ToString(), TotalAnnotationsCount);
}
