// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenNyxianBlackSapPostProcessAdapter.generated.h"

/**
 * UAshenNyxianBlackSapPostProcessAdapter
 * Modulates dark violet-black oily edge vignette and chromatic aberration during transference spikes and black sap cough moments.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNyxianBlackSapPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNyxianBlackSapPostProcessAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | PostProcess")
	float BlackSapVignetteIntensity = 0.0f; // 0.0 to 1.0

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | PostProcess")
	void ApplyBlackSapVignette(float BurnoutScalar);
};
