// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenLevelStreamingSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLevelStreamingStateChangedSignature, FName, LevelName, bool, bIsLoaded);

/**
 * UAshenLevelStreamingSubsystem
 *
 * World subsystem managing seamless level streaming transitions between Frozen Tarn surface exploration
 * and isolated Mindscape collapse level pockets using UGameplayStatics::LoadStreamLevel / UnloadStreamLevel.
 */
UCLASS()
class ASHENOATH_API UAshenLevelStreamingSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Streaming")
	void LoadLevelStream(FName LevelName);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Streaming")
	void UnloadLevelStream(FName LevelName);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Streaming")
	TArray<FName> ActiveLoadedLevels;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Streaming|Events")
	FOnLevelStreamingStateChangedSignature OnLevelStreamingStateChanged;

private:
	UFUNCTION()
	void HandleLevelLoaded();

	UFUNCTION()
	void HandleLevelUnloaded();

	FName PendingLoadLevel = NAME_None;
	FName PendingUnloadLevel = NAME_None;
};
