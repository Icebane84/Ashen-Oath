// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "AshenBestiaryFinisherPostProcessAdapter.generated.h"

/**
 * UAshenBestiaryFinisherPostProcessAdapter
 * Inverted temporal monochrome for Echo-Maimer, cryo-thermal frost vignette for Slag-Serpent, holy starburst flare for Grief-Sworn.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBestiaryFinisherPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBestiaryFinisherPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyBestiaryFinisherPostProcess(EAshenPartyFinisherType FinisherType, float Intensity);
};
