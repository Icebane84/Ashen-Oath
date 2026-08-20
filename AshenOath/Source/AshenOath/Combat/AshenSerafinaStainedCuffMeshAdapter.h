// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaStainedCuffMeshAdapter.generated.h"

/**
 * UAshenSerafinaStainedCuffMeshAdapter
 * Modulates Serafina's arm and cuff material instances, driving oily black soot stain coverage (0.0 to 1.0) on her white wool cuffs.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaStainedCuffMeshAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSerafinaStainedCuffMeshAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Somatic")
	float BlackSapStainCoverage = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic")
	void UpdateCuffStain(float TransferenceScalar);
};
