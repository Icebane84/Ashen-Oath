// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "AshenBestiaryFinisherSaveGameAdapter.generated.h"

/**
 * UAshenBestiaryFinisherSaveGameAdapter
 * Serializes unlocked bestiary finisher lore entries and execution statistics into persistent save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBestiaryFinisherSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBestiaryFinisherSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeBestiaryFinisherToSave(EAshenPartyFinisherType FinisherType, bool bLoreUnlocked);
};
