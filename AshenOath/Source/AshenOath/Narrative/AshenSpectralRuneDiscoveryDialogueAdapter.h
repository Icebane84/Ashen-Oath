// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSpectralRuneDiscoveryDialogueAdapter.generated.h"

/**
 * UAshenSpectralRuneDiscoveryDialogueAdapter
 * Lorekeeper and companion lines upon discovering hidden ancient runes with the lantern.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSpectralRuneDiscoveryDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSpectralRuneDiscoveryDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerRuneDiscoveryDialogue(FName RuneTag);
};
