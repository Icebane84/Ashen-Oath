// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AshenOathPlayerController.generated.h"

class UInputMappingContext;
class UUserWidget;

/**
 *  Basic PlayerController class for a third person game
 *  Manages input mappings
 */
UCLASS(abstract)
class AAshenOathPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAshenOathPlayerController();


protected:


	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category ="Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category="Input|Input Mappings")
	TArray<UInputMappingContext*> MobileExcludedMappingContexts;

	/** Mobile controls widget to spawn */
	UPROPERTY(EditAnywhere, Category="Input|Touch Controls")
	TSubclassOf<UUserWidget> MobileControlsWidgetClass;

	/** Pointer to the mobile controls widget */
	UPROPERTY()
	TObjectPtr<UUserWidget> MobileControlsWidget;

	/** If true, the player will use UMG touch controls even if not playing on mobile platforms */
	UPROPERTY(EditAnywhere, Config, Category = "Input|Touch Controls")
	bool bForceTouchControls = false;

	/** Gameplay initialization */
	virtual void BeginPlay() override;

	/** Input mapping context setup */
	virtual void SetupInputComponent() override;

	/** Returns true if the player should use UMG touch controls */
	bool ShouldUseTouchControls() const;

public:
	// --- Developer Playtest Cheats (Console Exec Commands) -------------------

	/** Console command: AshenAddImprint <Weight> -- Adds psychological imprint to player buffer. */
	UFUNCTION(Exec, Category = "AshenOath|Cheats")
	void AshenAddImprint(float Weight = 0.2f);

	/** Console command: AshenTriggerIntegration -- Triggers Heartstone integration ritual. */
	UFUNCTION(Exec, Category = "AshenOath|Cheats")
	void AshenTriggerIntegration();

	/** Console command: AshenAddCurrency <Embers> <Ash> -- Grants Embers and Ash currency. */
	UFUNCTION(Exec, Category = "AshenOath|Cheats")
	void AshenAddCurrency(float Embers = 100.0f, float Ash = 50.0f);

	/** Console command: AshenSetLens <LensIndex> -- Sets active lens (0=Accountability, 1=Grace, 2=Utility). */
	UFUNCTION(Exec, Category = "AshenOath|Cheats")
	void AshenSetLens(int32 LensIndex);
};

