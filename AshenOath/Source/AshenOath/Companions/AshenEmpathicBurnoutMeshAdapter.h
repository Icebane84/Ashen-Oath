// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEmpathicBurnoutMeshAdapter.generated.h"

/**
 * UAshenEmpathicBurnoutMeshAdapter
 * Modulates Serafina's dynamic skin material parameters: waxy desaturation and cyanotic blue fingernail tint scaling with Empathic Burnout.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEmpathicBurnoutMeshAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEmpathicBurnoutMeshAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Somatic")
	float WaxySkinDesaturationScalar = 0.0f; // 0.0 to 1.0

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Somatic")
	float CyanoticNailTintScalar = 0.0f; // 0.0 to 1.0

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic")
	void UpdateBurnoutVisuals(float BurnoutAmount);
};
