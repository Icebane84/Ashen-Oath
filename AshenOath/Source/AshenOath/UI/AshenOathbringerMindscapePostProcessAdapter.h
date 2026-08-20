// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenOathbringerMindscapeComponent.h"
#include "AshenOathbringerMindscapePostProcessAdapter.generated.h"

/**
 * UAshenOathbringerMindscapePostProcessAdapter
 * Inverted void bloom and blood-mist chromatic distortion during real-time sword morphing and inner mindscape battles.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerMindscapePostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenOathbringerMindscapePostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyMindscapePostProcess(EAshenSwordMorphState MorphState, float Intensity);
};
