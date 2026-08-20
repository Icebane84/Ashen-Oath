// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_MemoryConstellationGraph.generated.h"

UENUM(BlueprintType)
enum class EAshenMemoryStarType : uint8
{
	Ordinary         UMETA(DisplayName = "Ordinary Experience"),
	Defining         UMETA(DisplayName = "Defining Memory"),
	BrokenTrauma     UMETA(DisplayName = "Broken Trauma"),
	DarkPulsing      UMETA(DisplayName = "Dark Pulsing Unresolved"),
	GoldenIntegrated UMETA(DisplayName = "Golden Integrated Identity")
};

/**
 * UAshenUserWidget_MemoryConstellationGraph
 *
 * UMG backing widget for Memory Constellation ("Why am I like this?").
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_MemoryConstellationGraph : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void InspectMemoryStar(FName MemoryNodeID, EAshenMemoryStarType StarType, FString CompanionPerspective);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName ActiveSelectedMemoryNodeID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	EAshenMemoryStarType ActiveStarType = EAshenMemoryStarType::Ordinary;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FString ActiveCompanionPerspectiveText;
};
