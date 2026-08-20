// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "AshenCompanionMeshSootAdapter.generated.h"

class USkeletalMeshComponent;
class UMaterialInstanceDynamic;

/**
 * UAshenCompanionMeshSootAdapter
 * 
 * Drives dynamic material parameters on companion meshes:
 * - Serafina: Transference soot creep up arms and wrists (SootIntensity parameter)
 * - Garrett: Combat wear, armor mud, and fatigue scarring (CombatWear parameter)
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionMeshSootAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionMeshSootAdapter();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Updates material dynamic parameters */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Companions|Mesh")
	void UpdateCompanionMeshScalars(float SootOrWearIntensity);

	UFUNCTION(BlueprintPure, Category = "Ashen|Companions|Mesh")
	float GetCurrentMaterialScalar() const { return CurrentIntensity; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Companions|Mesh")
	FName MaterialScalarParameterName = FName(TEXT("EmpathicSootIntensity"));

protected:
	UPROPERTY()
	USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial;

private:
	float CurrentIntensity = 0.0f;
	float TargetIntensity = 0.0f;
};
