// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VFX/AshenShadowMarkVFXTypes.h"
#include "AshenShadowSeepageAIDirectorComponent.generated.h"

/**
 * UAshenShadowSeepageAIDirectorComponent
 * AI Director modulating beast terror states and void cultist worship/aggression multipliers when Kaelen is in unchained seepage phases.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenShadowSeepageAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenShadowSeepageAIDirectorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	float CalculateEnemyPanicRadius(EShadowSeepagePhase Phase) const;
};
