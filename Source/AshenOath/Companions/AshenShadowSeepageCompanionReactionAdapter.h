// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VFX/AshenShadowMarkVFXTypes.h"
#include "AshenShadowSeepageCompanionReactionAdapter.generated.h"

/**
 * UAshenShadowSeepageCompanionReactionAdapter
 * Modulates companion combat proximity spacing and emergency transference prep when Kaelen enters unchained seepage phases.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenShadowSeepageCompanionReactionAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenShadowSeepageCompanionReactionAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	float EvaluateCompanionProximityOffset(EShadowSeepagePhase Phase) const;
};
