// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMindscapeDungeonGenerationSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMindscapeDungeonGeneratedSignature, int32, DungeonSeed, FName, LayoutTheme);

/**
 * UAshenMindscapeDungeonGenerationSubsystem
 *
 * World Subsystem procedural seed generator for Mindscape horror dungeon layouts.
 */
UCLASS()
class ASHENOATH_API UAshenMindscapeDungeonGenerationSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|MindscapeGeneration")
	void GenerateMindscapeDungeonLayout(int32 Seed, FName Theme);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MindscapeGeneration|Events")
	FOnMindscapeDungeonGeneratedSignature OnDungeonGenerated;

private:
	int32 ActiveSeed = 0;
};
