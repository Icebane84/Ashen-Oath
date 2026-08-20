// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenSomaticCharacterMeshAdapter.generated.h"

class USkeletalMeshComponent;
class UMaterialInstanceDynamic;

/**
 * UAshenSomaticCharacterMeshAdapter
 * 
 * Material and skeletal animation adapter driving:
 * - Idle hand tremors (MotorTremorIntensity)
 * - Dark Nightsteel vein creep material scalar (ParasitePressure & Corruption)
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticCharacterMeshAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticCharacterMeshAdapter();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Updates material dynamic parameters from somatic expression intent */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Mesh")
	void UpdateSomaticMeshParameters(float MotorTremor, float ParasitePressure, float Corruption);

	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Mesh")
	float GetCurrentVeinCreepScalar() const { return CurrentVeinCreep; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Mesh")
	float GetCurrentTremorScalar() const { return CurrentTremor; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Combat|Mesh")
	FName VeinMaterialParameterName = FName(TEXT("ShadowVeinIntensity"));

protected:
	UPROPERTY()
	USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial;

private:
	float CurrentVeinCreep = 0.0f;
	float TargetVeinCreep = 0.0f;

	float CurrentTremor = 0.0f;
	float TargetTremor = 0.0f;
};
