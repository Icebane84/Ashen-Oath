// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenExistentialMeaningTypes.generated.h"

UENUM(BlueprintType)
enum class ETrialOfWillChoice : uint8
{
	None       UMETA(DisplayName = "None / Inaction"),
	Defiance   UMETA(DisplayName = "Defiance (I Will Not Yield - Blade Plant)"),
	Wrath      UMETA(DisplayName = "Wrath (If I Burn, You Burn - Necrotic Slam)"),
	Trust      UMETA(DisplayName = "Trust (We Carry This Together - Bulwark Fallback)")
};

UENUM(BlueprintType)
enum class EKeystoneInterpretiveLens : uint8
{
	Accountability UMETA(DisplayName = "Accountability ('It was my weakness')"),
	Grace          UMETA(DisplayName = "Grace ('We survived together')"),
	Utility        UMETA(DisplayName = "Utility ('Pain is a variable')")
};

USTRUCT(BlueprintType)
struct FMemoryEchoRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Meaning")
	FName MemoryID = NAME_None; // e.g. FallOfOakhaven

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Meaning")
	FString MemoryTitle = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Meaning")
	EKeystoneInterpretiveLens SelectedLens = EKeystoneInterpretiveLens::Grace;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Meaning")
	bool bIsIntegrated = false;
};
