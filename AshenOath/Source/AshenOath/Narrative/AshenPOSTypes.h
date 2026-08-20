// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenPOSTypes.generated.h"

UENUM(BlueprintType)
enum class EAshenSingleQuestionScreen : uint8
{
	ExpeditionLog,     // "What have we learned?"
	CampRelationships, // "How are we doing?"
	PhysicalEquipment, // "What am I carrying?"
	MemoryConstellation, // "Why am I like this?"
	HeartstoneSanctuary, // "Who do I become next?"
	ReflectionTimeline   // "How did we get here?"
};

USTRUCT(BlueprintType)
struct FAshenQualitativeMindState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|POS")
	FText MindStateText; // e.g., "Fracturing (High Static Noise)"

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|POS")
	FText CharacterStanceText; // e.g., "Unshakeable / Resolute"

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|POS")
	FText RelationalAnchorText; // e.g., "Connected"

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath|POS")
	FText TacticalSynergyText; // e.g., "Synchronized / In Lockstep"
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSingleQuestionScreenChanged, EAshenSingleQuestionScreen, PreviousScreen, EAshenSingleQuestionScreen, NewScreen);
