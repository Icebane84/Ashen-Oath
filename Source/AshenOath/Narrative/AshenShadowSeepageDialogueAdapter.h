// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VFX/AshenShadowMarkVFXTypes.h"
#include "AshenShadowSeepageDialogueAdapter.generated.h"

/**
 * UAshenShadowSeepageDialogueAdapter
 * Manages companion voice barks reacting directly to Kaelen's physical shadow mark seepage and unchained static outbursts.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenShadowSeepageDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenShadowSeepageDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerSeepageReactionBark(FName CompanionID, EShadowSeepagePhase Phase);
};
