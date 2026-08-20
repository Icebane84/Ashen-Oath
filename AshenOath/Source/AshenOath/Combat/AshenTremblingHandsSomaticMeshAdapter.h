// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenTremblingHandsSomaticMeshAdapter.generated.h"

/**
 * UAshenTremblingHandsSomaticMeshAdapter
 * Modulates procedural skeletal mesh hand and forearm trembling jitter during the 50% trigger lock struggle.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTremblingHandsSomaticMeshAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTremblingHandsSomaticMeshAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Somatic")
	float TrembleAmplitudeScalar = 0.0f; // 0.0 to 1.0

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic")
	void UpdateTrembleAmplitude(float InTremble);
};
