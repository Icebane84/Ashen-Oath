// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "AshenOath_DirectorSubsystem.generated.h"

// Forward declarations for the classes we will hold weak pointers to.
class APawn;
class UQuestSystem; // Assumed class for quest management
class UVFXManager;  // Assumed class for VFX pooling/management

/**
 * @class UAshenOath_DirectorSubsystem
 * @brief PHOENIX CODEX: The central reference gateway for globally accessible, persistent systems.
 *
 * This subsystem acts as a fast, safe, and decoupled replacement for expensive lookups like
 * GetAllActorsOfClass. Core gameplay systems and actors register themselves here upon initialization.
 * Other objects can then query the Director to get a valid pointer to the systems they need.
 *
 * All references are stored as weak pointers (TWeakObjectPtr) to prevent blocking garbage collection
 * and to ensure validity before access.
 */
UCLASS(Config = Game, BlueprintType)
class ASHENOATH_API UAshenOath_DirectorSubsystem final : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	/** Static accessor to get the subsystem from a World Context Object. */
	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Director", meta = (WorldContext = "WorldContextObject"))
	static UAshenOath_DirectorSubsystem* Get(const UObject* WorldContextObject)
	{
		if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
		{
			return UGameInstance::GetSubsystem<UAshenOath_DirectorSubsystem>(World->GetGameInstance());
		}
		return nullptr;
	}

	// --- Registration Methods ---

	/** Registers the primary player pawn. Typically called from the Pawn's BeginPlay. */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Director")
	void SetPlayerPawn(APawn* InPlayerPawn);

	/** Registers the Quest management system. */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Director")
	void SetQuestSystem(UQuestSystem* InQuestSystem);

	/** Registers the VFX management system. */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Director")
	void SetVFXManager(UVFXManager* InVFXManager);

	// --- Accessor Methods ---

	/** Gets the registered Player Pawn, if valid. Returns nullptr otherwise. */
	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Director")
	APawn* GetPlayerPawn() const;

	/** Gets the registered Quest System, if valid. Returns nullptr otherwise. */
	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Director")
	UQuestSystem* GetQuestSystem() const;

	/** Gets the registered VFX Manager, if valid. Returns nullptr otherwise. */
	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Director")
	UVFXManager* GetVFXManager() const;

private:
	// --- Sovereign Registries ---

	/**
	 * @var PlayerPawn
	 * A weak pointer to the currently active player pawn.
	 */
	UPROPERTY(Transient)
	TWeakObjectPtr<APawn> PlayerPawn;

	/**
	 * @var QuestSystem
	 * A weak pointer to the active quest management system.
	 */
	UPROPERTY(Transient)
	TWeakObjectPtr<UQuestSystem> QuestSystem;

	/**
	 * @var VFXManager
	 * A weak pointer to the active VFX pooling and management system.
	 */
	UPROPERTY(Transient)
	TWeakObjectPtr<UVFXManager> VFXManager;
};
