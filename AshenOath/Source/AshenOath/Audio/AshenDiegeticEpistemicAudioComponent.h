// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenEpistemicConsequenceTypes.h"
#include "AshenDiegeticEpistemicAudioComponent.generated.h"

/**
 * UAshenDiegeticEpistemicAudioComponent
 * Manages spatial sound effects for Tier III Milestone harmonic chimes, Tier II discovery stingers, and quill writing textures.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticEpistemicAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticEpistemicAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayTierResolutionAudioCue(EConsequenceProfileTier Tier, bool bIsSynarchy);
};
