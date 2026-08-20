// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMarginaliaMeshAdapter.generated.h"

class USkeletalMeshComponent;
class UMaterialInstanceDynamic;

/**
 * UAshenMarginaliaMeshAdapter
 * 
 * Drives dynamic material parameters on the 3D physical journal prop:
 * - Cover wear, soot smudges, and strap distress
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMarginaliaMeshAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMarginaliaMeshAdapter();

	virtual void BeginPlay() override;

	/** Updates journal prop wear parameters */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Journal|Mesh")
	void UpdateJournalWear(float WearIntensity, float SootIntensity);

	UFUNCTION(BlueprintPure, Category = "Ashen|Journal|Mesh")
	float GetJournalWear() const { return CurrentWear; }

protected:
	UPROPERTY()
	USkeletalMeshComponent* JournalSkeletalMesh;

	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial;

private:
	float CurrentWear = 0.0f;
};
