// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulConstellationTypes.h"
#include "AshenLensPostProcessAdapter.generated.h"

/**
 * UAshenLensPostProcessAdapter
 * Manages post-process grading for lenses: Amber warmth for Grace, steel-blue sharpness for Accountability, high-contrast monochrome for Utility.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLensPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLensPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyLensColorGrading(EInterpretiveLens Lens);
};
