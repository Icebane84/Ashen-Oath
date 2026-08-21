// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "AshenHistoricalLoreRegistryComponent.generated.h"

/**
 * UAshenHistoricalLoreRegistryComponent
 * 
 * Master catalog registering core canon lore entries and relic definitions.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenHistoricalLoreRegistryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenHistoricalLoreRegistryComponent();

	/** Gets a default canonical lore text template */
	UFUNCTION(BlueprintPure, Category = "Ashen|Archive")
	FText GetDefaultLoreTemplate(ECodexCategory Category) const;
};
