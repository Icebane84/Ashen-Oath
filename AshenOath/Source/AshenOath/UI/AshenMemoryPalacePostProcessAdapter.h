// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMemoryPalacePostProcessAdapter.generated.h"

/**
 * UAshenMemoryPalacePostProcessAdapter
 * Manages post-process dream grading: ethereal chromatic dispersion, constellation star lines, and psychic bloom.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryPalacePostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMemoryPalacePostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyMindscapeDreamGrading(bool bInMindscape, float TraumaDensity);
};
