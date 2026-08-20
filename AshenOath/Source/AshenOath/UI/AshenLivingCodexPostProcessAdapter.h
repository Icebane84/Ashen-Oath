// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenLivingCodexTypes.h"
#include "AshenLivingCodexPostProcessAdapter.generated.h"

/**
 * UAshenLivingCodexPostProcessAdapter
 * Manages illuminated manuscript golden bloom, depth-of-field background defocus, and runic shimmer when reading codex entries.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLivingCodexPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLivingCodexPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void SetCodexReadingVisualState(bool bIsReading, ECodexFaction Faction);
};
