// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenMemoryPalaceGraphTypes.generated.h"

UENUM(BlueprintType)
enum class EMemoryNodeType : uint8
{
	CoreSanctuary    UMETA(DisplayName = "Core Sanctuary"),
	TraumaNexus      UMETA(DisplayName = "Trauma Nexus"),
	EchoLocus        UMETA(DisplayName = "Echo Locus"),
	SunderedBridge   UMETA(DisplayName = "Sundered Bridge"),
	LorekeeperVault  UMETA(DisplayName = "Lorekeeper Vault")
};

UENUM(BlueprintType)
enum class EMemoryTraumaLevel : uint8
{
	Dormant          UMETA(DisplayName = "Dormant"),
	Moderate         UMETA(DisplayName = "Moderate"),
	Severe           UMETA(DisplayName = "Severe"),
	Catastrophic     UMETA(DisplayName = "Catastrophic")
};

USTRUCT(BlueprintType)
struct FMemoryGraphNode
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	FName NodeID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	EMemoryNodeType NodeType = EMemoryNodeType::EchoLocus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	EMemoryTraumaLevel TraumaLevel = EMemoryTraumaLevel::Dormant;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	FVector WorldPosition = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	bool bIsUnsealed = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	bool bIsReconstructed = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	TArray<FName> ConnectedNodeIDs;
};
