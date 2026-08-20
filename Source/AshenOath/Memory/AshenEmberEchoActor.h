// AshenEmberEchoActor.h
// Copyright Ashen Oath. All rights reserved.
// PHOENIX CODEX: ENGINE-SPEC-001 (DEFINITIVE CANON) & Pillar III
// Soulslike death corpse retrieval echo actor holding lost Embers.
#pragma once

#include "CoreMinimal.h"
#include "AshenInteractableActor.h"
#include "AshenEmberEchoActor.generated.h"

/**
 * @class AAshenEmberEchoActor
 * @brief Spawned at death location when Kaelen dies before Heartstone.
 *
 * Interacting with this actor restores lost Embers to Kaelen's CurrencyComponent.
 */
UCLASS()
class ASHENOATH_API AAshenEmberEchoActor : public AAshenInteractableActor
{
	GENERATED_BODY()

public:
	AAshenEmberEchoActor();

	/** Initialize the echo with the amount of Embers lost at death. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Echo")
	void SetStoredEmbers(float InEmbers) { StoredEmbers = InEmbers; }

	/** Returns stored Embers. */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Echo")
	float GetStoredEmbers() const { return StoredEmbers; }

protected:
	virtual void BeginPlay() override;
	virtual void Interact_Implementation(APawn* Player) override;


private:
	UPROPERTY(EditAnywhere, Category = "AshenOath|Echo")
	float StoredEmbers = 0.0f;
};
